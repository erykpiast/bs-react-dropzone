[@bs.config {jsx: 2}];

open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let renderReason = () => (
/* react-dropzone uses `forwardRef` and hooks on the root element
* what causes issues when rendered directly through shallow renderer
* Using Fragment (</>) triggers another kind of error, so plain old div
* isn't as bad as you may think
*/
<div>
    <ReactDropzone.Jsx2>
    ...{(_) => ReasonReact.null}
    </ReactDropzone.Jsx2>
</div>
) |> Enzyme.shallow |> Enzyme.Shallow.childAt(0);

let renderJs = [%bs.raw "() => React.createElement(require('react-dropzone').default, {}, () => null)"];

describe("jsx2", () => {
  test("output equal to direct JS rendering", () => {
    let reasonComponent = renderReason();
    let jsComponent = [%bs.raw "renderJs()"];

    expect(Enzyme.Shallow.equals(jsComponent, reasonComponent)) |> toBe(true)
  });
});